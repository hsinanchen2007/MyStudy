### 解题思路
    第一遍，遍历两个字符串找出公牛，将未匹配的秘密串放入哈希表中。未匹配的猜的串先放在容器中等待和哈希表匹配。哈希表要设为HashMap而不是HashSet，HashMap中的Vaule要存放该字符的个数。当列表和HashMap匹配时如果匹配上一个就数量减一。如果数量为0及时移除哈希表。要一个一个匹配。防止一个哈希表中的元素和guess字符串中的字符发生了多次匹配。

### 代码

```java
class Solution {
    public String getHint(String secret, String guess) {
        int aCount=0;
        int bCount=0;
        ArrayList<Character> list= new ArrayList<>(); //<Character>表示字符
        HashMap<Character,Integer> map= new HashMap<>();
        //第一遍遍历：找出公牛，将位置不匹配的字符放到哈希表中，key值为字符名字，value值为出现的次数
        for(int i=0;i<secret.length();i++)
        {
            char temp=secret.charAt(i);
            if(temp==guess.charAt(i))
                aCount++;
            else
            {
                list.add(guess.charAt(i));  //猜的字符串中不匹配的元素先列表中等待匹配
                if(map.containsKey(temp))   //秘密字符串中不匹配的元素放到哈希表中
                {
                    map.put(temp,map.get(temp)+1);
                }
                else
                    map.put(temp,1);
            }
        }
        //第二遍：在Hash表中找出所有的母牛，如果有对上的就是母牛
        for(Character c:list)
        {
            if(map.containsKey(c))
            {
                bCount++;
                map.put(c,map.get(c)-1);
                //减1之后若减为0应立刻清除
                if(map.get(c)==0)
                    map.remove(c);
            }
        }
        return aCount+"A"+bCount+"B";
    }
}
```