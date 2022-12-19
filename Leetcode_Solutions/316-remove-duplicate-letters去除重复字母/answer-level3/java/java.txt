class Solution {
    public String removeDuplicateLetters(String s) {
        /*
        1、字母需要录入的情况有两种：此字母是当前未录入序列中最小 or 此字母在未录入序列中不再出现
            按照这个思路 当出现这两种情况时，录入 begin-当前位置 ，但是由于上述情况时动态的，固定一个字符后会影响后续字符的判定条件
            比较好的方法是递归处理，但是效率可能会降低
        2、栈：
            使用栈记录当前动态的由小到大的偏序，如果新位置的字符比栈顶小，则弹栈
            但是在用set标记哪些字符已经符合 两种情况 的字符，这些字符是不能被弹出的
        这里使用方法2：
        */
        
        //初始处理，存入chars数组记录出现次数
        Set<Character> set = new HashSet<>();
        int[] chars = new int[26];
        Arrays.fill(chars,0);
        int len = s.length();
        for(int i=0 ; i<len ; i++){
            chars[s.charAt(i)-'a']++;
        }
    
        Stack<Character> stack = new Stack<>();//维持一段偏序序列
        StringBuilder ret = new StringBuilder();
        for(int i=0 ; i<len ; i++){
            char cur = s.charAt(i);
            if(stack.search(cur) == -1 ){//已出现的不再重复考虑,因为已占据当前最小位置 如：m t m n，跳过第二个m
                while(!stack.empty() && !set.contains(stack.peek()) && stack.peek()-cur>0){
                    stack.pop();
                }
                stack.push(cur);
            }
            chars[cur-'a']--;
            if(chars[cur-'a'] == 0){
                set.add(cur);//标记这些字符不可被弹出
            }
        }
        
        while(!stack.empty()){
            ret.append(stack.pop());
        }
        return ret.reverse().toString();
    }
}