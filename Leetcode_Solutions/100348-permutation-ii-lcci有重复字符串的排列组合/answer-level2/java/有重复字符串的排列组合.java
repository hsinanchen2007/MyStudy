### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String[] permutation(String S) {
        List<String> list=new ArrayList<>();
        char [] arr=S.toCharArray();
        Arrays.sort(arr);
        boolean [] used=new boolean[arr.length];
        dfs(list, new StringBuilder(),used,arr);
        
        String [] res=new String[list.size()];
        for(int i=0;i<res.length;i++)
            res[i]=list.get(i);
        return res;
    }

    public void dfs(List<String> res,StringBuilder sb,boolean [] used,char [] arr)
    {
        if(sb.length()==used.length){
            res.add(sb.toString());
            return;
        }
        for(int i=0;i<arr.length;i++){
            if(!used[i]){
                if(i>0&&arr[i]==arr[i-1]&&!used[i-1])
                    continue;
                else
                {
                    sb.append(arr[i]);
                    used[i]=true;
                    dfs(res,sb,used,arr);
                    used[i]=false;
                    sb.deleteCharAt(sb.length()-1);
                }
            }
        }
    }
}
```