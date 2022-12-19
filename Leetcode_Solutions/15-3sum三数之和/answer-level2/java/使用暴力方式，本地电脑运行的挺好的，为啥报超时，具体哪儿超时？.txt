使用暴力方式，本地电脑运行的挺好的，为啥在leetcode环境报超时。


public List<List<Integer>> threeSum(int[] nums) {

        List<List<Integer>> fList = new ArrayList<List<Integer>>();

        int fnum = 0;
        int snum = 0;
        int tnum = 0;
        int zeroNum = 0;
        int len = nums.length;
        for(int i=0;i<len-2;i++){
            for(int j=i+1;j<len-1;j++){
                for(int k=j+1;k<len;k++){
                    fnum = nums[i];
                    snum = nums[j];
                    tnum = nums[k];
                    if(fnum + snum + tnum == 0){
                        List<Integer> iList = new ArrayList<Integer>();
                        iList.add(fnum);
                        iList.add(snum);
                        iList.add(tnum);
                        if(fnum == 0&&snum == 0&&tnum == 0&&zeroNum==0){
                            fList.add(iList);
                            zeroNum = zeroNum+1;
                            continue;
                        }
                        if(!isContains(fList,iList)){
                            fList.add(iList);
                        }
                    }

                }

            }
        }

       return fList;
    }

    private boolean isContains(List<List<Integer>> fList, List<Integer> iList){
       for(List<Integer> list : fList){

          if(list.containsAll(iList)) {
              return true;
          }
        }
        return false;
    }