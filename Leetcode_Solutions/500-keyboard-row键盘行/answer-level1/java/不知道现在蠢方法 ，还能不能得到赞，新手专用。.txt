```
class Solution {
    public String[] findWords(String[] words) {
        String test = "qwertyuiopQWERTYUIOP";
        String test01 = "asdfghjklASDFGHJKL";
        String test02 = "zxcvbnmZXCVBNM";
        ArrayList<String>res=new ArrayList<>();
        for (int i = 0; i <words.length ; i++) {
            int count = 0;
            int count01 = 0;
            int count02 = 0;
            for (int j = 0; j <words[i].length() ; j++) {
                //**判断字符串test中是否含有该字母，如果有增1**
                if(test.indexOf(words[i].charAt(j))>=0){
               count++;
                }
                else if(test01.indexOf(words[i].charAt(j))>=0){
                    count01++;
                }
                else if(test02.indexOf(words[i].charAt(j))>=0){
                    count02++;
                }
            }
            //**若数下来的count值等于其长度，则增入res中**
            if (count==words[i].length()||count01==words[i].length()||count02==words[i].length()){
                res.add(words[i]);
            }

        }
        //**array变成字符串数组，不知道这一步有没有必要**
        String [] result = new String[res.size()];
        for (int i = 0; i <res.size() ; i++) {
            result[i]=res.get(i);
        }
        return result;
    }
}
```
