```
    public boolean oneEditAway(String first, String second) {
        int flen = first.length(), slen = second.length();
        if(Math.abs(flen-slen)>1) return false;
        if(first.equals("")||second.equals(""))return true;
        boolean[] mark = new boolean[1];
        return Judge(first, second, 0, 0, mark);
    }
    public boolean Judge(String first, String second, int fs, int ss, boolean[] mark){
        while(fs<first.length()&&ss<second.length()){
            if(first.charAt(fs)==second.charAt(ss)){
                fs++;
                ss++;
            }else{
                if(!mark[0]){
                    mark[0] = true;
                    return Judge(first,second,fs+1, ss+1, mark)||Judge(first,second,fs, ss+1, mark)||Judge(first,second,fs+1, ss, mark);
                }
                return false;
            }
        }
        if(fs==first.length()&&ss==second.length()) return true;
        else if((fs==first.length()||ss==second.length())&&!mark[0]) return true;
        else return false;
    }
```
