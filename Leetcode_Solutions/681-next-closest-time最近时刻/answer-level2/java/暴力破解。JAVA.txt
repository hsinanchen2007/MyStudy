class Solution {
    public String nextClosestTime(String time) {
        String ret = "" ;
        int count=23*60+59;
      String str= time.substring(0,2)+time.substring(3);
      for(char ch1:str.toCharArray()){
          for(char ch2:str.toCharArray()){
              for(char ch3:str.toCharArray()){
                  for(char ch4:str.toCharArray()){
                      StringBuilder tmp = new StringBuilder();
                      tmp.append(ch1);
                      tmp.append(ch2);
                      tmp.append(":");
                      tmp.append(ch3);
                      tmp.append(ch4);
                      //System.out.println(tmp.toString());
                      if(Judege(tmp.toString()) ==1 ){
                          int iTmp = 0 ;
                          iTmp=getDiv(time,tmp.toString());
                          if(iTmp!=0 && iTmp<count){
                              count=iTmp;
                              ret=tmp.toString();
                          }
                      }
                  }
              }
          }
      }
        

      if(time.charAt(0)==time.charAt(1) && time.charAt(3)==time.charAt(4) && time.charAt(0)==time.charAt(3)){
          return time;
      }
      return ret;
    }

    private int getDiv(String time1,String time2){
        int hour1 = Integer.parseInt(time1.substring(0,2));
        int hour2 = Integer.parseInt(time2.substring(0,2));
        int ret = 0 ;
        ret = hour2*60 - hour1*60;
        ret= ret + Integer.parseInt(time2.substring(3));
        ret = ret - Integer.parseInt(time1.substring(3));
        if(ret<0){
            ret+=24*60;
        }
        return ret ;
    }

    private int Judege(String time1){
        if(time1.charAt(0)=='2' && time1.charAt(1)<'4' && time1.charAt(3)<'6'){
            return 1 ;
        }
        if((time1.charAt(0)=='1' || time1.charAt(0)=='0')  && time1.charAt(3)<'6'){
            return 1 ;
        }
        return 0 ;
    }    
  
}