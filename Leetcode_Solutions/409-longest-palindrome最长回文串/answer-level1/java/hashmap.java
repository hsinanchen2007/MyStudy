### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
  HashMap<Character,Integer> map = new HashMap<>();
for(int i = 0;i < s.length();i++)
{
if(!map.containsKey(s.charAt(i)))
{
map.put(s.charAt(i),1);
}
else
{
int count = map.get((s.charAt(i)))+1;
map.put(s.charAt(i),count);
}
}
int sum =0;
if(map.get((s.charAt(0))) == s.length())
{
return s.length();
}

     for (Integer value : map.values()) {
            if( value.intValue() %2 == 0)
            {
                sum += value.intValue();
            } else
                {
                    sum += value.intValue()-1;
                }
        }
if(sum < s.length())
{
sum +=1;
}
return sum;
}

    }
```