class Solution {
    public String replaceSpace(String s) {
        StringBuilder m = new StringBuilder();
        for(int i = 0; i <s.length(); i++)
        {
            if(s.charAt(i) != ' ')
                m.append(s.charAt(i));
            else
                m.append("%20");
        }
        return m.toString();
    }
}