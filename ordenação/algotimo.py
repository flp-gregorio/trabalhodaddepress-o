def dual_pivot_quicksort(arr, left, right):
    if right <= left:
        return
    
    # escolhendo os dois pivôs aleatórios
    if arr[left] > arr[right]:
        arr[left], arr[right] = arr[right], arr[left]
    p = arr[left]
    q = arr[right]
    
    # particionando a lista com base nos pivôs
    l = left + 1
    g = right - 1
    k = l
    while k <= g:
        if arr[k] < p:
            arr[k], arr[l] = arr[l], arr[k]
            l += 1
        elif arr[k] >= q:
            while arr[g] > q and k < g:
                g -= 1
            arr[k], arr[g] = arr[g], arr[k]
            g -= 1
            if arr[k] < p:
                arr[k], arr[l] = arr[l], arr[k]
                l += 1
        k += 1
    
    # colocando os pivôs em suas posições finais
    l -= 1
    g += 1
    arr[left], arr[l] = arr[l], arr[left]
    arr[right], arr[g] = arr[g], arr[right]
    
    # chamando a função recursivamente para as sub-listas
    dual_pivot_quicksort(arr, left, l - 1)
    if arr[l] < arr[g]:
        dual_pivot_quicksort(arr, l + 1, g - 1)
    dual_pivot_quicksort(arr, g + 1, right)