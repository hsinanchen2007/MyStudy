1, 构建一个长度为n的list,元素全部为1, 即 res = [1]*(n)
2, 用list模拟一个最小堆minheap. list每次加进来元素都会去重再升序排列. 
3, 第一个丑数是 1 ==> res[0]为1, 然后用第一个丑数分别乘以{2,3,5} 把三个乘积分别加入minheap.
4, 那么第二个丑数就是 minheap里最小的那个数==>minheap[0]. 把它pop出来作为第二个丑数==>res[1]
5, res[1] = 2 然后用第二个丑数分别乘以{2,3,5}，放进最小堆中，从堆中取出堆顶(最小值)，即为第三个丑数res[2]
6, 循环n次 得到 res 就是前n个丑数. res[-1] 即为第n个丑数.

请问这个算法是不是暴力算法? 时间和空间复杂度分别是多少?
```
def nthUglyNumber(n):
    res = [1]*(n)
    minheap = [2,3,5]
    for i in range(1,n):
        minheap = sorted(set(minheap))
        res[i] = minheap.pop(0)

        minheap.append(res[i]*2)
        minheap.append(res[i]*3)
        minheap.append(res[i]*5)
    return res[-1]

```
