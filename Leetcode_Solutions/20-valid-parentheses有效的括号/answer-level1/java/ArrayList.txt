由于新手，做之前还不知道Stack<>的使用，就用了Arraylist，逻辑是和栈一样的

public boolean isValid(String s) {
        ArrayList<Character> xx = new ArrayList<>();
        for(int i = 0;i < s.length();++i){
            if(s.charAt(i) == '{' || s.charAt(i) == '(' || s.charAt(i) == '['){
                xx.add(s.charAt(i));
            }else if(xx.size()>0){
                if(s.charAt(i) == '}' && xx.get(xx.size()-1) == '{'){
                    xx.remove(xx.size()-1);
                }else if(s.charAt(i) == ')' && xx.get(xx.size()-1) == '('){
                    xx.remove(xx.size()-1);
                }else if(s.charAt(i) == ']' && xx.get(xx.size()-1) == '['){
                    xx.remove(xx.size()-1);
                }else {
                    return false;
                }
            }else {
                return false;
            }
        }
        if(s.length() % 2 == 0 && xx.size() == 0)
            return true;
        else
            return false;
    }