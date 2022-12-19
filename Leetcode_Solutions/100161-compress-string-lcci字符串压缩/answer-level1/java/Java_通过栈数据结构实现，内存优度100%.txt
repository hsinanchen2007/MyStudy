class Solution {
    public String compressString(String S) {
        StringBuilder stringBuilder = new StringBuilder();
        Stack<Character> uniqueCharStack = new Stack<>();
        int sum=0;
        for (char oneChar : S.toCharArray()) {
            if(uniqueCharStack.isEmpty()){
                uniqueCharStack.push(oneChar);
                sum++;
            }else{
                if(uniqueCharStack.peek().equals(oneChar)){
                    sum++;
                }else{
                    stringBuilder.append(uniqueCharStack.pop()+""+sum);
                    uniqueCharStack.push(oneChar);
                    sum=1;
                }
            }
        }
        if(!uniqueCharStack.isEmpty()){
            stringBuilder.append(uniqueCharStack.pop()+""+sum);
        }
        String rstStr = stringBuilder.toString();
        if (rstStr.length() >= S.length()) {
            return S;
        } else {
            return rstStr;
        }
    }
}