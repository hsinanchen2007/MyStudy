### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> transformArray(int[] arr) {
        List<Integer> res=new ArrayList<>();
        int [] dfs=dfs(arr);
        for(int df:dfs)
            res.add(df);
        return res;
    }

    private int [] dfs(int[] arr){
        //注意：不能在原来的数组上做++、--操作，否则影响对下一个元素的判断
        int [] clone=arr.clone();
        boolean flag=false;
        for(int i=1;i<arr.length-1;i++){
            if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])
            {
                clone[i]--;
                flag=true;
            }
            else if(arr[i]<arr[i+1]&arr[i]<arr[i-1]){
                clone[i]++;
                flag=true;
            }
        }
        if(flag)  //如果上一次有变化，那么久再来一遍
            return dfs(clone);
        return clone;
    }
}
```