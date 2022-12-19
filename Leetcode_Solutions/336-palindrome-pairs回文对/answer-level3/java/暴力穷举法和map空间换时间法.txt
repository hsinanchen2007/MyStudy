### 解题思路
（1）穷举法  通过测试用例  115/134
（2）map时间换空间法  100%

### 代码

```java
import java.util.*;

public class No1_palindromePairs {
    /**
     * 暴力  
     * 两两穷举。2Cn2=n(n-1)种str=str1+str2，每次用i，j分别从前后进行遍历，判断是否相等，时间复杂度为O（n^2*k）,n是单词个数，k是最长的单词长度
     * @param words
     * @return
     */
    public List<List<Integer>> palindromePairs1(String[] words) {
        List<List<Integer>> ans=new ArrayList<>();
        for (int i = 0; i <words.length-1 ; i++) {
            for (int j = i+1; j <words.length ; j++) {
                String s1=words[i]+words[j];
                if (isPalindrome(s1)){
                    ans.add(Arrays.asList(i,j));
                }
                String s2=words[j]+words[i];
                if (isPalindrome(s2)){
                    ans.add(Arrays.asList(j,i));
                }
            }
        }
        return ans;
    }

    private boolean isPalindrome(String s1) {
        int i=0,j=s1.length()-1;
        while (i<=j){
            if (s1.charAt(i++)!=s1.charAt(j--))
                return false;
        }
        return true;
    }

    /**
     * 不需要两两穷举
     * 用空间换时间；用一个map存储
     * 思路参考 ：https://blog.csdn.net/mayifan_blog/article/details/86726888
     * @param words
     * @return
     */
    public List<List<Integer>> palindromePairs2(String[] words) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        Map<String,Integer> dict = new HashMap<>();
        for(int i = 0;i < words.length;i++) {
            dict.put(words[i], i);
        }
        for(int j = 0;j < words.length;j++) {
            String str = words[j];
            int left = 0;
            int right = 0;
            while(left <= right) {
                String tmpstr = str.substring(left, right);
                Integer k = dict.get(new StringBuilder(tmpstr).reverse().toString());
                int l = left == 0?right:0;
                int r = left == 0?str.length():left;
                if(k != null && k != j && isPalindrome(str.substring(l, r))) {
                    ans.add(Arrays.asList(left == 0?new Integer[] {j,k}:new Integer[] {k,j}));
                }
                if(right < str.length())right++;
                else left++;
            }
        }
        return ans;
    }

}
```