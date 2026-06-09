class StringIterator {
    private String str = "";
    char currC;
    int  count=0, pos=0;
    public StringIterator(String compressedString) {
        str = compressedString;
    }

    public char next() {
        while (count==0&&str!=null&&pos<str.length()){
            currC = str.charAt(pos);
            pos++;
            while (pos<str.length() && str.charAt(pos)>='0'&&str.charAt(pos)<='9')
                count = count*10 + (str.charAt(pos++)-'0');
        }
        if (count==0) return ' ';

        count--;
        return currC;
    }

    public boolean hasNext() {
        return str!=null&&(count>0||pos!=str.length());
    }
}