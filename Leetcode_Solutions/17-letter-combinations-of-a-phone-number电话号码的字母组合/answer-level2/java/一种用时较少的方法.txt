![Snipaste_2020-02-24_13-26-15.png](https://pic.leetcode-cn.com/e7cd9a4de9ad496b9deb1e1051604fa6ca9481a3a636c4eb1871d27381a9b8d4-Snipaste_2020-02-24_13-26-15.png)
先计算一共可能有多少种排列组合。
比如说“23” 2对应3个字母“abc” ；3对应3个字母“def” 那么一共就有9种组合（3*3）
现在我们要确定在这9种情况中在考虑“2”时对应的哪种情况，在考虑“3”时对应的哪种情况；
写一个从0到8的循环表示这9中中情况
对于0来说它在“2”中对应到a，在“3”中对应到“d”
对于1来说它在“2”中对应到a，在“3”中对应到“e”
……
对于8来说它在“2”中对应到c，在“3”中对应到“f”
由此可以发现一个规律，假设我们现在考察的是第i中组合，那么“2”对应的就是i/3，“3”对应的就是i%3；
推广到大于多个字符是代码如下
```
 public List<String> letterCombinations(String digits) {
        String[] cap={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n=digits.length();
        int sum=1;
        int[] cNum=new int[n];
        int p=0;
        for(int i=n-1;i>=0;i--){
            char t=digits.charAt(i);
            p=t-'2';
            cNum[i]=sum;
            sum*=cap[p].length();
        }

        List<String> result=new ArrayList<>();
        for(int i =0;i<sum;i++){
            StringBuilder s=new StringBuilder("");
            int temp=i;
            for(int  j=0;j<n;j++){
                int y=temp/cNum[j];
                temp=temp%cNum[j];
                char t=digits.charAt(j);
                int r=t-'2';
                s.append(cap[r].charAt(y));
            }
            result.add(s.toString());
        }
        return result;

    }
```



