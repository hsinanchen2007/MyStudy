### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        int x,z;
        List<Integer> list=new ArrayList<>();
        for(int i=left;i<=right;i++){
            z=i;
            while(i!=0){
                x=i%10;
                if(x==0){
                    i=1;
                    break;
                }
                if(z%x!=0) break;
                i/=10;
            }
            if(i==0){
                list.add(z);
            }
            i=z;
        }
        return list;
    }
}
```