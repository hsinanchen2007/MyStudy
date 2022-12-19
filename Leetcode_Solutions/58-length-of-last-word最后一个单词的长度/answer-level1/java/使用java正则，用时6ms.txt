public int lengthOfLastWord(String s) {
        if( s.matches("\\s+$")){
            return 0;
        }else{
            //         按照空格将字符串分割
            String[] arr=s.split(" ");
            int lastIndex=arr.length-1;
            //         记录最后一个字符串的长度
            int lastLen=0;
            lastLen=arr[lastIndex].length();
            return lastLen;
        }

    }
