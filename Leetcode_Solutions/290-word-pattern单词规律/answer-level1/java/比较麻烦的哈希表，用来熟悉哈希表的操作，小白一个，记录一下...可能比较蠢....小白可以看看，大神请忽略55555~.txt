### 解题思路
1.全部在代码里面注释了，小白一个。。。有改进的地方欢迎大佬指正。。。

### 代码

```java
class Solution {
    public boolean wordPattern(String pattern, String str) {
        if(pattern.length()==0||str.length()==0){return false;}//判断pattern和str是否是空字符串，如果是，直接输出false。
        HashMap<Character, String> map = new HashMap<>();
        String[] strArr=str.split(" ");//题中给了str必定以空格“ ”分开单词，所以可以利用空格分成字符串数组.
        if(strArr.length!=pattern.length()){return false;}//判断分开后的字符串数组长度是否和规律字符串pattern长度相等，相等后再继续下面的哈希表，否则，直接输出false，不可能满足规律。
        map.put(pattern.charAt(0),strArr[0]);//先把第一对填入哈希表，从第二个数再循环判断。
        boolean res=true;//初始化一个boollean值。。。小白一个，这是习惯。。
        for(int i=1;i<pattern.length();i++){  //从第2个key和value观察循环观察。
            if(map.containsKey(pattern.charAt(i))){   //如果哈希表已经包含这个key；
                if(!strArr[i].equals(map.get(pattern.charAt(i)))){res=false;break;}//包含了key再看是否这个位置对应的value，是不是和已经保存的这个key对应的value相等，相等就不用操作，否则直接false，终止循环。
            }
             if(!map.containsKey(pattern.charAt(i))){  //如果哈希表没有包含这个key；分两种情况：
                 if (map.containsValue(strArr[i])){ //哈希表没有这个key，但是却包含了这个value，肯定不满足规律，直接false。
                    res=false;
                    break;
                }
                 if(!map.containsValue(strArr[i])){//哈希表没有这个key，而且没有包含对应的strArr中的value，也就是说这是新的一对 key和value，可以存进到哈希表中，所以存放进去，继续循环；
                map.put(pattern.charAt(i),strArr[i]);
                }
                }
            }
            return res;
        }

    }
```