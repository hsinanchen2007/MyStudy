 双指针，遍历一次分别记录大写字母和小写字母的个数，然后去判断三种情况即可，即全大写，全小写，只有首字母大写，三者均不符合则返回false即可      
 public boolean detectCapitalUse(String word) {
        int a = 0;
        int b = 0;
        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) >= 'A' && word.charAt(i) <= 'Z') {
                a++;
            }
            else {
                b++;
            }
        }
        if (a == word.length()) {
            return true;
        }
        else if (b == word.length()) {
            return true;
        }
        else if (a == 1 && word.charAt(0) >= 'A' && word.charAt(0) <= 'Z') {
            return true;
        }
        else {
            return false;
        }
    }