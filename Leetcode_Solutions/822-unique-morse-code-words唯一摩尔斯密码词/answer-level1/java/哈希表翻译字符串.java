1. 译码问题想到用哈希表，源码字母保存为键，译码摩尔斯密码保存为对应值；
2. 遍历words表中的每个单词，将它翻译成对应摩尔斯密码的组合
3. 用HashSet保存结果，并返回集合的大小

```
    public int uniqueMorseRepresentations(String[] words) {
        HashMap<Character,String> map = new HashMap();
        String[] list = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
                    ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--",
                "-..-","-.--","--.."};
        for (int i = 0; i < list.length; i++) {
            map.put((char)(i+97),list[i]);
        }
        //检查map，键为“a、b、c”，值为摩尔斯密码
//        for (Character character : map.keySet()) {
//            System.out.println(character);
//        }
//        String[] outString = new String[words.length];
        HashSet<String> set = new HashSet();
        for (int i=0;i<words.length;i++) {
            StringBuffer sb = new StringBuffer();//sb表示翻译后的摩尔斯密码
            char[] alphabet = words[i].toCharArray();
            for (char c : alphabet) {
                sb.append(map.get(c));
            }
//            outString[i] = sb.toString();
            set.add(sb.toString());
        }
        //检查outString
//        System.out.println(Arrays.toString(outString));
        return set.size();
    }
```
