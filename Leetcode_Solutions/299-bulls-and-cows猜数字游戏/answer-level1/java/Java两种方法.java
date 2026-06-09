**方法一**：我的思路很简单，先遍历一次字符串，如果两个字符串当前索引字符相同，则将"公牛数"加一；否则，将秘密字符串的字符放入HashMap中，进行次数统计，将猜的字符放入一个Array中。
第一次遍历完毕后进行第二次遍历，此时的array中是猜的字符串中没有对上号的字符，依次获取array中的字符，看HashMap中是否有该字符，如果有，则让"母牛数"加一，然后将该字符的次数减一，如果该字符在Map中的次数为零则清除。
方法一代码如下：
```java
    /*
        Time complexity: O(n)
        Space complexity: O(n)
     */
    public String getHint(String secret, String guess) {
        int aCount = 0;
        int bCount = 0;
        ArrayList<Character> list = new ArrayList<>();
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < secret.length(); i++) {
            char temp = secret.charAt(i);
            if (temp == guess.charAt(i))
                aCount++;
            else {
                list.add(guess.charAt(i));
                if (map.containsKey(temp))
                    map.put(temp, map.get(temp) + 1);
                else
                    map.put(temp, 1);
            }
        }
        for (Character c : list) {
            if (map.containsKey(c)) {
                bCount++;
                map.put(c, map.get(c) - 1);
                if (map.get(c) == 0)
                    map.remove(c);
            }
        }
        return aCount + "A" + bCount + "B";
    }
```
**方法二**：由于猜的数字只包括0~9这九位数字，因此我们可以定义两个10位数组来存储某个数出现的次数，索引代表数值，索引处的值代表次数。
思路如下：先遍历一次字符串，如果字符相等，公牛数加一，否则，将它们对应的数组中的次数加一。
第一次遍历完毕后可以得到两个数组，分别对应了两个字符串中某一个数出现的次数(匹配的字符不算)，然后我们可以再进行一次遍历，两个数组每一个索引处的最小值相加即可得到母牛数。
代码如下：
```java
    /*
        Time complexity: O(n)
        Space complexity: O(1)
     */
    public String getHint(String secret, String guess) {
        int aCount = 0;     // 公牛数
        int bCount = 0;     // 母牛数
        //int mapS[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        //int mapG[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int[] mapS[] = new int[10];
        int[] mapG[] = new int[10];

        for (int i = 0; i < secret.length(); i++) {
            char temp = secret.charAt(i);
            if (temp == guess.charAt(i))
                aCount++;
            else {
                mapS[temp - '0']++;
                mapG[guess.charAt(i) - '0']++;
            }
        }
        for (int i = 0; i < 10; i++) {
            bCount += Math.min(mapG[i], mapS[i]);
        }
        return aCount + "A" + bCount + "B";
    }
```