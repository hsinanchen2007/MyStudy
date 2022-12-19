比较字母的asci值   
执行用时 :0 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :38.7 MB, 在所有 java 提交中击败了98.21%的用户
public char nextGreatestLetter(char[] letters, char target) {
        for (char letter : letters) {
        	if( (int)letter > (int)target ) {
        		return letter;
        	}
        }
        
        return letters[0];
    }