### 代码

```java
class Solution {
    Set<String> set=new HashSet<>();
    public String[] permutation(String s) {
       char[] ch=s.toCharArray();
       boolean [] flag=new boolean[s.length()];
       dfs(ch,"",0,flag);
       return set.toArray(new String[set.size()]);
    }

    public void dfs(char [] ch, String str, int count, boolean []flag){
        if(count==ch.length){
            set.add(str);
            return ;
        }
        for(int i=0;i<ch.length;i++){
            if(!flag[i]){
                flag[i]=!flag[i];
                dfs(ch,str+ch[i],count+1,flag);
                flag[i]=!flag[i];
            }
        }
    }
}
```