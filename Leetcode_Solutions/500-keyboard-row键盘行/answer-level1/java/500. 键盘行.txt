
/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/19
 *
 * 解题思路: 使用hash 将每一个字母的对应的行进行映射 然后最每一个单词进行hash扫描，查看是否处在同一行
 *
 */
```
public String[] findWords(String[] words) {

    char[] line1 = "qwertyuiop".toCharArray();
    char[] line2 = "asdfghjkl".toCharArray();
    char[] line3 = "zxcvbnm".toCharArray();

    int[] letter = new int[26];

    for(int i = 0;i < line1.length;i++){
        letter[line1[i] - 'a'] = 1;
    }

    for(int i = 0;i < line2.length;i++){
        letter[line2[i] - 'a'] = 2;
    }

    for(int i = 0;i < line3.length;i++){
        letter[line3[i] - 'a'] = 3;
    }

    ArrayList arrays = new ArrayList<String>();
    for(int i = 0;i < words.length;i++){
        char[] t = words[i].toLowerCase().toCharArray();
        int line = letter[t[0] - 'a'];
        for(int j = 1;j < t.length;j++){
            //int l = letter[t[i] - 'a'];
            if(line != letter[t[j] - 'a']){
                line = -1;
                break;
            }
        }
        if(line != -1){
            arrays.add(words[i]);
        }
    }

    String[]  res = new String[arrays.size()];
    for(int i = 0;i < arrays.size();i++){
        res[i] = (String) arrays.get(i);
    }

    return res;
}
```