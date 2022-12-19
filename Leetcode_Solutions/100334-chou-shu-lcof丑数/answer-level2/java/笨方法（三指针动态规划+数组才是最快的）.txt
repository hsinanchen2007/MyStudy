### 解题思路
List+寻找丑数的方法
用数组和指针是最快的
用三个指针记录增长的增长头部位置，只要比较头部三个值中的最小值就可以了。
### 代码

```java
class Solution {
    public int nthUglyNumber(int n) {
        List<Integer> list = new ArrayList<>(n);
        list.add(1);
        int[] min = {0,0,0};
        for(int i = 1 ; i < n ; i++){
            findUN(list,i,min);
        }
        return list.get(n-1);
    }
    private void findUN(List<Integer> list,int n,int[] min){
        int a = 0,b = 0,c = 0;
        for(int i = min[0] ; i < n ; i++){
            if(list.get(i)*2 > list.get(n-1)){
                min[0] = i;
                a = list.get(i)*2;
                break;
            }
        }
        for(int i = min[1] ; i < n ; i++){
            if(list.get(i)*3 > list.get(n-1)){
                min[1] = i;
                b = list.get(i)*3;
                break;
            } 
        }
        for(int i = min[2] ; i < n ; i++){
            if(list.get(i)*5 > list.get(n-1)){
                min[2] = i;
                c = list.get(i)*5;
                break;
            }
        }
        list.add(Math.min(Math.min(a,b),c));
    }
}
```