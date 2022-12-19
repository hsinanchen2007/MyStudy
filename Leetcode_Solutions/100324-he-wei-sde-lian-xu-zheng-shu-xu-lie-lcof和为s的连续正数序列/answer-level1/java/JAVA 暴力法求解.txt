### 解题思路
此处撰写解题思路
先求ArrayList;
再将ArrayList转化为二维数组：
List<List<Integer>> res = new ArrayList<>();
int[][] arr = new int[res.size()][];//定义二维数组
for(int i=0;i<res.size();i++){
    arr[i] = new int[res.get(i).size()];//创建一维数组
    for(int j=0;j<res.get(i).size();j++){
        arr[i][j] = res.get(i).get(j);
    }
}
### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<List<Integer>> res = new ArrayList<>();
        for(int i =1;i<=(target+1)/2;i++){
            int j = i;
            List<Integer> list = new ArrayList<>();
            int sum = 0;
            while(j<=(target+1)/2){
                sum += j;
                list.add(j);
                if(sum>target){
                    break;
                }else if(sum==target){
                    res.add(list);
                    break;
                }
                j++;
            } 
        }
        int[][] arr = new int[res.size()][];
        for(int i=0;i<res.size();i++){
            arr[i] = new int[res.get(i).size()]; 
            for(int j=0;j<res.get(i).size();j++){
                arr[i][j] = res.get(i).get(j);
            }
        }
        
        return arr;
    }
}
```