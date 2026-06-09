class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.length()==0){
            return 0;
        }
        LinkedList<Character> queue = new LinkedList<Character>();
        int maxLen = 1;
        char[] chars = s.toCharArray();
        queue.addLast(chars[0]);
        for(int i=1;i<chars.length;i++){
            while(queue.contains(chars[i])){
                queue.removeFirst();
            }
            queue.addLast(chars[i]);
            if(queue.size()>maxLen){
                maxLen=queue.size();
            }
        }
        return maxLen;
    }
}