    string toHex(int num) {
        //key step
        unsigned int num1 = (unsigned int)num;
        string ans;
        do{
            switch(num1%16){
                case 10:ans = "a"+ans;break;
                case 11:ans = "b"+ans;break;
                case 12:ans = "c"+ans;break;
                case 13:ans = "d"+ans;break;
                case 14:ans = "e"+ans;break;
                case 15:ans = "f"+ans;break;
                default:ans = to_string(num1%16)+ans;
            }
            num1 = num1/16;
        }while(num1!=0);
        return ans;
    }