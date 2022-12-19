### 解题思路
此处撰写解题思路
此题解法受[http://zxi.mytechroad.com/blog/searching/leetcode-17-letter-combinations-of-a-phone-number/](花花酱的博客)启发。
对于做combination，即叉乘的题目可以用DFS去解答。这就像一棵树一样，第一层是“2”，第二层是”3“，然后在里面像是对树一样做DFS。
### 代码

```java
class Solution {
    public List<String> letterCombinations(String digits) {
        String[] letters = new String[]{" ", 
                                "", 
                                "abc", 
                                "def",
                                "ghi",
                                "jkl",
                                "mno",
                                "pqrs",
                                "tuv",
                                "wxyz"};  
        // 由于需要一个容器来盛放所有的答案，我们可以创建一个List让他在每个recursion中使用
        List<String> result=new ArrayList<String>();
        // 这里我是认为花花酱比较机智的一点，因为我之前的思路是用string不停地加，这样缺点就是容易出现"a", "ad", "ade", "adf"的结果，其实就是因为没有意识到数字和字母映射的关系，只有建一个char[]可以避免这个问题，下面会说
        char[]cur=new char[digits.length()];
        dfs(digits,letters,0,cur,result);
        return result;
    }

    private void dfs(String digits, String[] letters, int currentIndex, char[]cur, List<String> result){
        System.out.println(currentIndex);
        if(currentIndex>=digits.length()){
            // 这里再加一个判定主要是因为testcase会有一个输入是""。然后这里主要就是在一个分叉上面将字母iterate完成后，将当前结果当做string放入result中，并返回到上一级去继续执行那个for loop然后去下一个分支
            if(currentIndex>0)result.add(new String(cur));
            return;
        }

        String currentIterate=letters[Character.getNumericValue(digits.charAt(currentIndex))];
        // System.out.println(currentIterate);
        for (int i=0; i<currentIterate.length(); i++){
            // 这里就是cur的妙处，如果用string的+=是没有办法替换掉相同位置上的字母的（即："ad"不会变成"ae"，而是"ade"），这里用char[]就可以在index上做一个一一对应，把已经iterate完成的index给换成新的。
            cur[currentIndex]=currentIterate.charAt(i);
            dfs(digits, letters, currentIndex+1,cur,result);
        }


    }
}
```