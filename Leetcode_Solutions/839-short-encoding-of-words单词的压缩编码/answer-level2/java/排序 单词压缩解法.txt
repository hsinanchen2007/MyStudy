1.先将数组中字符串按照每个字符串长度排序
2.拼接字符串并且判断当前字符串是否在已经编码过的字符串里
```
public int minimumLengthEncoding(String[] words) {
            StringBuffer stringBuffer = new StringBuffer();
            for (int i = 0; i < words.length; i++) {
                String temp =words[i];
                int max = i;
                for (int j = i+1; j < words.length; j++) {
                    if(temp.length()<words[j].length()){
                        max = j;
                    }
                }
                words[i] = words[max];
                words[max] = temp;
            }
            for (int i = 0; i < words.length; i++) {
                //int index = 0;
                if(null != stringBuffer && stringBuffer.toString().contains(words[i]+"#")){
                    //index = stringBuffer.indexOf(words[i]);
                }else{
                    // if(i == words.length-1){
                    //     stringBuffer.append(words[i]);
                    // }else{
                        stringBuffer.append(words[i]).append("#");
                        //index = stringBuffer.indexOf(words[i]);
                    // }
                }
                 
        }
        return stringBuffer.length();
    }
```
