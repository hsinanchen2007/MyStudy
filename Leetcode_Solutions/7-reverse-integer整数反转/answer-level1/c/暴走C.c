    int reverse(int x){
        int hash[10] = {0}; //保存每一位的值
        
        //将负数当成正数处理，在最后返回时加上符号即可
        int fu = 0;
        if(x < 0){
            fu = 1;
            //注意此处负值是到-2的31次方，而正值仅仅到2的31次方-1
            if(x < -INT_MAX ){
                return 0;
            }else{
                x = -x;
            }
        }
        
        //将x的每一位取出来放到hash数组里待用
        int i = 0;
        while(x != 0){
            hash[i++] = x % 10;
            x/=10;
        }
        
        /*
        for(int k = 0; k < 10; k++){
            printf("hash[%d] = %d\n", k, hash[k]);
        }
        printf("i = %d\n", i);
        */
        
        //遍历hash数组，将每一位乘上相应的10的次方然后累加到res值
        i--;
        int res = 0;
        int j = 0;
        while(i >= 0){
            //判断是否整数溢出，一旦溢出就返回0
            if(hash[j]*pow(10, i) <= INT_MAX -res){
                res += hash[j]*pow(10,i);
            }else{
                return 0;
            }
            i--;
            j++;
        }
        
        //判断是否是负数，如果是就返回-res
        if(fu){
            return -res;
        }else{
            return res;
        }
        
    }