解题思路：
按照一个最复杂的数,依次判断每一部分，
0、空格
1、+-
2、num
3、.
4、num
5、e
6、+-
7、num
8、空格

其中，没有num一定要返回false；

代码如下（这破代码我是看不下去的）：

bool InRomanNum (char a){
    if ( a >= '0' && a <= '9'){
        return true;
    }
    
    return false;
}

bool isNumber(char * s){
    int len = strlen(s);
    //printf("len: %d\r\n",len);
    int index = 0;
    int numCnt = 0;

    /*去头空格*/
    while(s[index] == ' ') {
        index++;
        //printf("get blank\r\n");
        if (index == len && numCnt == 0){
            //printf("end false\r\n");
            return false;
        }
    } 

    /*判断+-*/
    if (s[index] == '+' || s[index] == '-'){

        if ((s[index + 1] == '+' || s[index + 1] == '-')){
            return false;
        }
        //printf("get +-\r\n");
        index++;
    }

    /*判断数字*/
    while(InRomanNum(s[index])) {
        index++;
        numCnt++;
        //printf("get num\r\n");
        if (index == len){
            //printf("end good\r\n");
            return true;
        }
    }       

    /*判断.*/
    if (s[index] == '.')
    {
        index++;
        //printf("get .\r\n");

        if (index == len)
        {
            if (numCnt == 0){
               // printf("end false\r\n");
                return false;  
            }
            else{
                //printf("end good\r\n");
                return true;
            }
        }

        /*.后不结束，则必须有数字*/
        while(InRomanNum(s[index])) {
            index++;
            numCnt++;
            //printf("get num\r\n");
            if (index == len){
                //printf("end goog\r\n");
                return true;
            }
        } 
    }

    /*如果还有e*/
    if (s[index] == 'e')
    {
        if (index == 0){
            //printf("end false\r\n");
            return false;   
        }

        if (numCnt == 0){
            //printf("end bad\r\n");
            return false;  
        }
        index++;
        //printf("get e\r\n");
        
        /*不能以e结束*/
        if (index == len){
            //printf("end bad\r\n");
            return false;
        }
        
        if (s[index] == '+' || s[index] == '-'){

            if ((s[index + 1] == '+' || s[index + 1] == '-')){
                return false;
            }
            //printf("get +-\r\n");
            index++;
        }

        if (false == InRomanNum(s[index])){
            //printf("end false\r\n");
            return false;
        }
        
        while(InRomanNum(s[index])) {
            index++;
            numCnt++;
            //printf("get num\r\n");
            if (index == len){
                //printf("end true\r\n");
                return true;
            }
        } 

    }

    /*去尾空格*/
    while(s[index] == ' ') {
        index++;
        //printf("get blank\r\n");
        
        if (index == len && numCnt != 0){
            //printf("end true\r\n");
            return true;
        }
    } 

    //printf("end false\r\n");
    return false;
}