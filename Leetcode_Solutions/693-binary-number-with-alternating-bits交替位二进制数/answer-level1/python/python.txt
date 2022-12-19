我用的是一种比较麻烦的方法，但是通俗易懂

```
count = 0
bin_n = bin(n).split('b')[-1]
for i in range(len(bin_n)-1):
    if bin_n[i] != bin_n[i+1]:
        count += 1
if count == len(bin_n) - 1:
    return True
else:
    return False
```
  
