### 解题思路
此处撰写解题思路
根据题意将数字放入数组中，依次移除即可。
1.当m>n时,需要减去重复的，有可能转了几圈。计算出最后的坐标进行移除就可以了
2.当n>=m时，正常移除就可以了
### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {

        List<Integer> arr = new ArrayList<Integer>();
        for(int i=0;i<n;i++){
            arr.add(i);
        }
        boolean firstVal = true;
        int removeIndex = m-1;
        while(arr.size() != 1){
           if(m > n){
                if(firstVal) {
                    removeIndex = 0;
                    firstVal = false;
                }
                removeIndex = removeIndex + (m-arr.size()-1);
                while(removeIndex >= arr.size()){
                    removeIndex -= arr.size();
                }
                arr.remove(removeIndex);
           }else{

                arr.remove(removeIndex);
                removeIndex += m -1;
                while(removeIndex >= arr.size()){
                    removeIndex -= arr.size();
                }
           }
        }
        return arr.get(0);
    }
}
```