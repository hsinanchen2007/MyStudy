
`public static int countCharacters(String[] words, String chars) {

        ArrayList<Character> nums = new ArrayList<>();
        for (char charNum : chars.toCharArray()) {
            nums.add(charNum);
        }
        int allNum = 0;
        for (String word : words) {
            int count = 0;
            ArrayList<Character> numTemp = new ArrayList<>();
            for (char num : nums){
                numTemp.add(num);
            }//必须实现深拷贝，否则会导致删除numTemp元素的时候，同时删掉了nums的元素。
            for (int i = 0; i < word.length(); i++){
                if (numTemp.contains(word.charAt(i))){
                    for (int j = 0; j < numTemp.size();j++) {
                        if (numTemp.get(j) == word.charAt(i)){
                            numTemp.remove(j);
                            //ArrayList删除元素只能靠索引，有哪位大佬有什么好的方法一定告诉我ya。
                            break;
                        }
                    }
                    count++;
                }
            }
            if (count != word.length())
                count = 0;
            allNum += count;
        }

        return allNum;

    }`  
    本代码时间复杂度很高，只是为了熟练下ArrayArrayList的使用和对深拷贝的理解。

