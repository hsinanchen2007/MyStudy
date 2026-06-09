![image.png](https://pic.leetcode-cn.com/5b693634f6d05fcff2093a1f9f1eb89f06e0f32e167ff2f153443757e4b893a3-image.png)
按照题目的思路，用Map储存chars字典中出现过的字符及次数，并对于每个字符串检测是否可以拼写成功。
```
class Solution 
{
    public int countCharacters(String[] words, String chars) 
    {
        if(words.length==0||chars.length()==0)return 0;
        char[] ch=chars.toCharArray();
        HashMap<Character,Integer> map=new HashMap<>();
        int ans=0;
        for(char c:ch)
        {
            map.put(c,map.getOrDefault(c,0)+1);
        }
        int len=words.length;
        for(int i=0;i<=len-1;i++)
        {
            boolean flag=false;
            char[] cc=words[i].toCharArray();
            HashMap<Character,Integer> temp=(HashMap)map.clone();
            for(int j=0;j<=cc.length-1;j++)
            {
                if(!map.containsKey(cc[j])){flag=true;break;}//no such,break
                else
                {
                    if(temp.get(cc[j])>=1)temp.put(cc[j],temp.get(cc[j])-1);//enough,then -1
                    else {flag=true;break;}//not enough,break
                }
            }
            if(flag)continue;
            ans+=words[i].length();
        }
        return ans;
    }
}
```
