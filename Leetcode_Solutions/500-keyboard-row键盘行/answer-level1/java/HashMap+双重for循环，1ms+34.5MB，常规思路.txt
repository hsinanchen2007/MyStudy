```
public static String[] findWords(String[] words) {
        HashMap<Character,Integer> map = getKeyBoardMap();
        ArrayList<String> list = new ArrayList<>();
        for(int i = 0;i<words.length;i++){
            String str = words[i].toLowerCase();
            boolean f = true;
            //获取每个字符串开头的字符的
            int index = map.get(str.charAt(0));
            for(int j = 1;j<str.length();j++){
                if(index != map.get(str.charAt(j))){
                    f = false;
                    break;
                }
            }
            if(f){
                list.add(words[i]);
            }
        }
        String[] strs = new String[list.size()];
        for(int i = 0;i<list.size();i++){
            strs[i] = list.get(i);
        }
        return strs;
    }
    public static HashMap<Character,Integer> getKeyBoardMap(){
        HashMap<Character,Integer> map = new HashMap<>();
        map.put('z',3);map.put('x',3);map.put('c',3);
        map.put('v',3);map.put('b',3);map.put('n',3);
        map.put('m',3);map.put('a',2);map.put('s',2);
        map.put('d',2);map.put('f',2);map.put('g',2);
        map.put('h',2);map.put('j',2);map.put('k',2);
        map.put('l',2);map.put('q',1);map.put('w',1);
        map.put('e',1);map.put('r',1);map.put('t',1);
        map.put('y',1);map.put('u',1);map.put('i',1);
        map.put('o',1);map.put('p',1);
        return  map;
    }
```

