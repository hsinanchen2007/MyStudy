### 解题思路
- 关键在于得到数组的长度。
- 以2、4、8、16……为数组下标不断尝试，直到数组越界，这时的下标比真正元素的个数大，但没有关系，只要适当改编一下普通的二分查找就可以了。
- 唯一与普通二分查找不同的是：若得到的中间下标已经越界，则查找中间下标左边的部分即可。


### 代码

```java
class Solution {
    public int search(ArrayReader reader, int target) {
        int index=2;
        while(reader.get(index)!=2147483647){
            index*=2;
        }
        return binsearch(reader,0,index,target);
    }
    private int binsearch(ArrayReader reader,int lo,int hi,int tar){
        
        while(lo<=hi){
            int md=lo+(hi-lo)/2;
            int tmp=reader.get(md);
            if(tmp==tar) return md;
            if(tmp==2147483647 || tar<tmp) hi=md-1;
            else lo=md+1;

        }
        return -1;
    }
}
```