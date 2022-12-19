### 解题思路
回溯算法
执行用时 :8 ms, 在所有 Java 提交中击败了82.77%的用户
内存消耗 :51 MB, 在所有 Java 提交中击败了100.00%的用户

### 代码

```java
class Solution {
    List<String> list = new ArrayList<>();
    public String[] permutation(String S) {
        char[] chars=S.toCharArray();
        boolean[] access=new boolean[chars.length];
        permutation(access,chars,new char[chars.length],0);
        return list.toArray(new String[list.size()]);
    }

    private void permutation(boolean[] access,char[] chars,char [] result,int index){
        if(index==chars.length){
            list.add(new String(result));
            return;
        }
        for(int i=0;i<chars.length;i++){
            if(access[i]){
                continue;
            }
            result[index]=chars[i];
            access[i]=true;
            permutation(access,chars,result,index+1);
            access[i]=false;

        }
    }
}
```