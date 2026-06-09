public int maxNumberOfBalloons(String text) {
        int[] balloon = new int[5];
        for(int i=0;i<text.length();i++){
            char current = text.charAt(i);
            switch (current){
                case 'b':{
                    balloon[0]++;
                }break;
                case 'a':{
                    balloon[1]++;
                }break;
                case 'l':{
                    balloon[2]++;
                }break;
                case 'o':{
                    balloon[3]++;
                }break;
                case 'n':{
                    balloon[4]++;
                }break;
            }
        }
        int min = Integer.MAX_VALUE;
        min=Math.min(min,balloon[0]);
        min=Math.min(min,balloon[1]);
        min=Math.min(min,balloon[4]);
        min=Math.min(min,balloon[2]/2);
        min=Math.min(min,balloon[3]/2);
        return min;
    }