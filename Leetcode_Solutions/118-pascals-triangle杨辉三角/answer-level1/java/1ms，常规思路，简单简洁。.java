![image.png](https://pic.leetcode-cn.com/9da0a38c159ecce018a2a0c4f0f806c2afbd725d71a8e34a195dbed367dc0667-image.png)

```
class Solution {
    public List<List<Integer>> generate(int numRows) {
        
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
       
        for(int i = 0; i < numRows; i++){
             List<Integer> array = new ArrayList<Integer>();
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    array.add(1);
                }else{
                    array.add(ans.get(i-1).get(j-1) + ans.get(i-1).get(j));
                }
            }
            ans.add(array);
        }
        return ans;
    }
    
}
```
