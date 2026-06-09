# 解题思路：
    利用HashMap保存不同的键值对集合，然后遍历匹配
# 代码：
```
public class Solution1 {

    HashMap<Character, String> patternMap = new HashMap<>();
    public boolean wordPattern(String pattern, String str) {
        char[] patternArray = pattern.toCharArray();
        String[] strArray = str.split(" ");
        
        if (strArray.length != patternArray.length){
            return false;
        }

        for (int i = 0; i < patternArray.length; i++){
            // 保存不同的pattern键
            if (!patternMap.containsKey(patternArray[i])){
                // 确保不同的pattern键对应的是不同的pattern值
                if (!patternMap.containsValue(strArray[i])) {
                    patternMap.put(patternArray[i], strArray[i]);
                }
            }
        }

        // 遍历一遍，进行匹配
        for (int i = 0; i < strArray.length; i++){
            if (!(patternMap.containsKey(patternArray[i])
            && (strArray[i].equals(patternMap.get(patternArray[i]))))){
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Solution1 solution1 = new Solution1();
        String pattern = "abba";
        String str = "dog dog dog dog";
        System.out.println(solution1.wordPattern(pattern, str));
    }
}
```
