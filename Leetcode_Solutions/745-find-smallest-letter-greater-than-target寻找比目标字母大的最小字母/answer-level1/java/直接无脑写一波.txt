  这个一开始想复杂了，本来想用二分法，后来想了想直接一个for循环就结束了
public char nextGreatestLetter(char[] letters, char target) {
        for (int i = 0; i < letters.length; i++) {
           if (letters[i] > target) {
                return letters[i];
            }
        }
        return letters[0];
    }