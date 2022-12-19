### 解题思路
回溯的写法非常标准，判断合适的条件，进行递归调用，递归调用之后要将改变的值恢复原状。
此处注意一点，当有很多种选择时，通常使用if（条件1）{改变状态；递归；恢复状态}；if（条件2）{改变状态；递归；恢复状态}；的写法，而不要用if else，用了if else 会在大循环的i++上面做改变，麻烦！

去重首先要排序，在排序过后，要么是设置每次递归的start值传参，要么设置lastChar值，用来与上一次迭代做对比。此处为全排列，不能使用start值（会漏情况），所以设置lastChar即可

### 代码

```java
class Solution {
    List<String> list = new ArrayList();
    public String[] permutation(String S) {
        char[] c=new char[S.length()];
        c = S.toCharArray();
        Arrays.sort(c);
        
        DFS(c ,new StringBuffer(), new boolean[S.length()]);
        String[] res = list.toArray(new String[list.size()]);
        return res;

    }
    
    public void DFS(char[] c, StringBuffer sb, boolean[] isSearched){
        if(sb.length() == c.length){
            list.add(new String(sb));
            return ;
        }
        
        char lastChar = ' ';
        
        for(int i = 0; i < c.length; i++){
            if(isSearched[i])   continue;
            if(i>0 && c[i]==lastChar) continue;
            
            sb.append(c[i]);
            isSearched[i] = true;
            DFS(c,sb,isSearched);
            isSearched[i] = false;
            sb.deleteCharAt(sb.length()-1); 
            lastChar = c[i];
        }
            
    }
}
```