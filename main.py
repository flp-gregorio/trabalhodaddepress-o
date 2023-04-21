import numpy as np
from ordenação import algotimo as al
a = [1,234,345,342,5634,523,52,564,6,345,2,345,235]
al.dual_pivot_quicksort(a, 0, len(a) - 1)

print(a)