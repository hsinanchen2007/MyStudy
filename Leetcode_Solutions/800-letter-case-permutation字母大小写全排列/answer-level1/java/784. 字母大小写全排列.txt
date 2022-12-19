/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/11
 * 
 * 解题思路: 此题首先要掌握排列树的基本使用 在排列树的基础上 遇到数字跳过即可 例子如图：
 * 
 * 后附上排列树 子集树参考代码
 * 
 
![DA2B2175F3CFF9DF780C525546F8A2EF.png](https://pic.leetcode-cn.com/10b29a164de6bf1236c406b8adea3c7c839435671d8df0e248cb6a36a16b7278-DA2B2175F3CFF9DF780C525546F8A2EF.png)
*/
```
class Solution {
    List<String> list = new ArrayList<>();
    public List<String> letterCasePermutation(String S) {
        char[] s_arr = S.toCharArray();
        ZJTreel(s_arr , 0);
        return list;
    }

    public void ZJTreel(char[] S , int  t){

        if(t > S.length - 1){
            list.add(String.valueOf(S));
        }else{
            if(S[t] >= '0' && S[t] <= '9'){
                ZJTreel(S , t + 1);
            }else{
                ZJTreel(S , t + 1);
                S[t] = (char)(S[t] > 'Z' ? S[t] - ('a' - 'A'):S[t] + ('a' - 'A')); //swap
                ZJTreel(S , t + 1);
                S[t] = (char)(S[t] > 'Z' ? S[t] - ('a' - 'A'):S[t] + ('a' - 'A')); //swap
            }
           
        }

    }
}


    /**
     * 子集树
     * @param S 字符数组
     * @param t 初始为0
     */
    public void ZJTree(char[] S , int t){
        if(t > S.length - 1){ // 子节点
            System.out.println(String.valueOf(S).replace("#",""));
        }else{ //非子结点
            ZJTree(S,t+1);
            char m = S[t];
            S[t] = '#'; //表示删除S[t]
            ZJTree(S,t+1);
            S[t] = m; //主要是在递归的过程中 S传递的是引用 不会对S现场进行保护 因此手动回复 或者上面使用 ZJTree(S.clone(),t+1);
        }
    }

    /**
     * 排列树
     * @param S 字符数组
     * @param t 初始为0
     */
    public void PLTree(char[] S , int t){
        if(t > S.length - 1){ // 子节点
            System.out.println(S);
        }else{ //非子结点
            for(int i = t;i < S.length;i++){ // 多叉树遍历
                swap(S,t,i);//两次swap 主要保证 第一个数与任何一位进行交换一次
                PLTree(S,t + 1);
                swap(S,t,i);
            }
        }
    }
    public void swap(char[] S , int l , int r){
        char t = S[l];
        S[l] = S[r];
        S[r] = t;
    }
```