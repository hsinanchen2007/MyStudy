**并查集:**  851 ms	41.1 MB	Java
```java
import java.util.Arrays;
import java.util.HashSet;

class Solution {

    int reBuild(int i, int A[]) {
        if (i != A[i]) {
            A[i] = reBuild(A[i], A);
        }
        return i;
    }

    void findP(int i, int A[], String[] W) {
        for (int j = 0; j < W.length; j++) {
            if (i != j && W[j].endsWith(W[i])) {
                A[i] = j;
                break;
            }
        }
    }

    public int minimumLengthEncoding(String[] words) {
        //利用set去重
        HashSet<String> set = new HashSet<>(Arrays.asList(words));
        String W[]=new String[set.size()];
        int idx=0;
        for(String s:set){
            W[idx++]=s;
        }
        //并查集初始化
        int []A =new int[W.length];
        for (int i = 0; i < A.length; i++) {
            A[i] = i;
        }
        //查找第i个字符的直接父节点
        for (int i = 0; i < A.length; i++) {
            findP(i, A, W);
        }
        //重构并查集，将第i个字符的父节点指向最终父节点（a->aa->aaa）->(a->aaa,aa->aaa)
        for (int i = 0; i < A.length; i++) {
            reBuild(i, A);
        }
        int rst = 0;
        //有几个最终父节点，将其长度相加，就是结果
        for (int i = 0; i < A.length; i++) {
            if (i == A[i])
                rst += W[i].length() + 1;//加1 是因为一个#号
        }
        return rst;
    }

    public static void main(String[] args) {
        String[]w=new String[]{"time", "me", "bell"};
        int c =new Solution().minimumLengthEncoding(w);
        System.out.println(c);
    }

}
```

**字典树的代码：**  14 ms	45 MB	Java
```java
import java.util.Arrays;

class Trie {
    int R = 26;
    char c;
    Trie[] W;

    Trie(char c) {
        this.c = c;
        W = new Trie[R];
    }

}


class Solution {

    int insert(String s, Trie root) {
        boolean isNew=false;
        char C[] = s.toCharArray();
        for(int i=C.length-1;i>-1;--i){//反着的插入
            if (root.W[C[i] - 'a'] == null) {
                root.W[C[i] - 'a'] = new Trie(C[i]);
                isNew=true;
            }
            root = root.W[C[i] - 'a'];
        }
        return isNew?s.length()+1:0;
    }

    public int minimumLengthEncoding(String[] words) {
        Arrays.sort(words, (a, b) -> b.length() - a.length());//先按长度，降序排序
        Trie root = new Trie('c');
        int rst = 0;
        for(String w:words){
            int cnt= insert(w,root);
            rst+=cnt;
        }
        return rst;
    }

    public static void main(String[] args) {
       int c= new Solution().minimumLengthEncoding(new String[]{"a", "aa", "aaa"});
        System.out.println(c);
    }
}
```