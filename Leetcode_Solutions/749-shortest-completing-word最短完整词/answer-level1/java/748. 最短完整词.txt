/**
 * Project:
 * Author : zhaozhen
 * Email  : 2399144252@qq.com
 * Date   : 2019/10/10
 * 
 * 解题思路1: 正则处理licensePlate 然后进行hash匹配 (正则很费时间)
 * 
 * 解题思路2: licensePlate 和 单词列表都进行hash 然后进行 暴力26 循环比对  来判断是否一个字符串每一个字符都存在于另一个字符串中
 *
 * 解题思路3：因为words的长度很小 索引可以不进行排序 直接使用一个str 来记录最优值 复杂度可以下降O(n*26)=O(n) 
 * 
 */
```
//14ms
 public String shortestCompletingWord(String licensePlate, String[] words) {
    Arrays.sort(words, new Comparator<String>() {
        @Override
        public int compare(String o1, String o2) {
            return o1.length() - o2.length();
        }
    });

    char[] licensePlate_arr = licensePlate.replaceAll("[^a-zA-z]","").toLowerCase().toCharArray();

    for(int i = 0;i < words.length;i++){
        boolean is_ok = true;
        
        int[] leeters = new int[26];
        char[] word = words[i].toCharArray();
        
        for(int j = 0; j < word.length;j++){
            leeters[word[j] - 'a'] ++;
        }
        
        for(int j= 0;j < licensePlate_arr.length;j++) {
            if(leeters[licensePlate_arr[j] - 'a'] == 0){
                is_ok = false;
            }else{
                leeters[licensePlate_arr[j] - 'a']--;
            }
        }
        if(is_ok) return words[i];
    }
    
    return "";
}

//9ms
public String shortestCompletingWord2(String licensePlate, String[] words) {
    //排序
    Arrays.sort(words, new Comparator<String>() {
        @Override
        public int compare(String o1, String o2) {
            return o1.length() - o2.length();
        }
    });

    //车牌hash
    char[] licensePlate_arr = licensePlate.toLowerCase().toCharArray();
    char[] licensePlate_letters = new char[26];
    for(int i = 0;i < licensePlate_arr.length;i++){
        if(licensePlate_arr[i] >= 'a' && licensePlate_arr[i] <= 'z'){
            licensePlate_letters[licensePlate_arr[i] - 'a']++;
        }
    }


    for(int i = 0;i < words.length;i++){
        //单词表hash
        boolean is_ok = true;
        int[] leeters = new int[26];
        char[] word = words[i].toCharArray();
        for(int j = 0; j < word.length;j++){
            leeters[word[j] - 'a'] ++;
        }

        //暴力26
        for(int j= 0;j < 26;j++) {
            if(leeters[j] < licensePlate_letters[j]){
                is_ok = false;
                break;
            }
        }
        if(is_ok) return words[i];
    }
    return "";

}

//4ms
public String shortestCompletingWord3(String licensePlate, String[] words) {


        //车牌hash
        char[] licensePlate_arr = licensePlate.toLowerCase().toCharArray();
        char[] licensePlate_letters = new char[26];
        for(int i = 0;i < licensePlate_arr.length;i++){
            if(licensePlate_arr[i] >= 'a' && licensePlate_arr[i] <= 'z'){
                licensePlate_letters[licensePlate_arr[i] - 'a']++;
            }
        }


        String str = "";

        for(int i = 0;i < words.length;i++){
            //单词表hash
            boolean is_ok = true;
            int[] leeters = new int[26];
            char[] word = words[i].toCharArray();
            for(int j = 0; j < word.length;j++){
                leeters[word[j] - 'a'] ++;
            }

            //暴力26
            for(int j= 0;j < 26;j++) {
                if(leeters[j] < licensePlate_letters[j]){
                    is_ok = false;
                    break;
                }
            }
            if(is_ok){
                if(str == ""){
                    str = words[i];
                }else if(str.length() > words[i].length()){
                    str = words[i];
                }
            }
        }
        return str;

}
```