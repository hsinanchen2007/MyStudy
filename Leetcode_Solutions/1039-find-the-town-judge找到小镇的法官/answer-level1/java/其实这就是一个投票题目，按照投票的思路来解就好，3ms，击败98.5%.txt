{

            int[]note = new int[N];

            if (N ==1 ) return 1; //只有一个人那就不用投票了，肯定是他

            for (int i=0;i<N;i++){
                note[i]= 0; //所有人都是0票，初始化
            }

            //开始记录选票
            for (int i=0;i<trust.length;i++){
                note[trust[i][1]-1]++;
            }

            //检查下有没有人得到除自己外所有人的投票数
            int flag =0;
            for (int i = 0;  i<N ; i++) {
                if (note[i] == N-1){
                    flag = i+1;
                }
            }

            if (flag ==0){
                return  -1; //没有人得到全票，没法确定人选
            }

            //有得到全票的，看看这个得票的人有没有投反对票
            for (int j = 0; j < trust.length; j++) {
                if (trust[j][0]== flag){
                    return -1;
                }
            }
            
            return flag;
        }