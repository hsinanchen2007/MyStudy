//特征
如果s3前缀(l3-1)是s1(l1-1)+s2(l2)前缀交错形成并且s3[len-1]==s1[l1-1]，
或者是s1(l1)+s2(l2-1)前缀交错形成并且s3[len-1]==s2[l2-1]，则s3是由s1与s2交错形成。

//自顶向下实现，较为符合人的思维
bool isComp(char * s1, char * s2, char * s3, int l1, int l2, int l3);
bool isComp(char * s1, char * s2, char * s3, int l1, int l2, int l3)
{
    //l1 == 0 && l2 == 0 
    if(l3 == 0)
    {
        return true;
    }
    //l2==0
    else if(l3 == l1)
    {
        if(0 == memcmp(s1, s3, l3))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //l1==0
    else if(l3 == l2)
    {
        if(0 == memcmp(s2, s3, l3))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //s3最后一个字符与谁相等
    if(s3[l3-1] == s1[l1-1] && isComp(s1, s2, s3, l1-1, l2, l3-1))
    {
        return true;
    }
    if(s3[l3-1] == s2[l2-1] && isComp(s1, s2, s3, l1, l2-1, l3-1))
    {
        return true;
    }
    return false;
}

bool isInterleave(char * s1, char * s2, char * s3){
    bool ret = false;
    int s1_len = (s1 ? strlen(s1) : 0);
    int s2_len = (s2 ? strlen(s2) : 0);
    int s3_len = (s3 ? strlen(s3) : 0);
    if(s1_len + s2_len != s3_len)
    {
        return false;
    }
    
    return isComp(s1,s2,s3,s1_len,s2_len,s3_len);
}

//自底向上实现，运行高效
bool isInterleave(char * s1, char * s2, char * s3){
    bool ret = false;
    int s1_len = (s1!=NULL ? strlen(s1) : 0);
    int s2_len = (s2!=NULL ? strlen(s2) : 0);
    int s3_len = (s3!=NULL ? strlen(s3) : 0);
    int l1 = 0;
    int l2 = 0;
    int l3 = 0;
    int i = 0;
    if(s1_len + s2_len != s3_len)
    {
        return false;
    }
    bool *rst = (bool *)malloc((s1_len+1)*(s2_len+1)*sizeof(bool));
    for(l1 = 0; l1 <= s1_len; l1++)
    {
        for(l2 = 0; l2 <= s2_len; l2++)
        {
            l3 = l1 + l2;
            //l1 == 0 && l2 == 0
            if(l3 == 0)
            {
                rst[l1*(s2_len+1)+l2] = true;
            }
            //l2==0
            else if(l2 == 0)
            {
                if(0 == memcmp(s1, s3, l3))
                {
                    rst[l1*(s2_len+1)+l2] = true;
                }
                else
                {
                    rst[l1*(s2_len+1)+l2] = false;
                }
            }
            //l1==0
            else if(l1 == 0)
            {
                if(0 == memcmp(s2, s3, l3))
                {
                    rst[l1*(s2_len+1)+l2] = true;
                }
                else
                {
                    rst[l1*(s2_len+1)+l2] = false;
                }
            }
            //s3最后一个字符与谁相等
            else if(s3[l3-1] == s1[l1-1] && rst[(l1-1)*(s2_len+1)+l2])
            {
                rst[l1*(s2_len+1)+l2] = true;
            }
            else if(s3[l3-1] == s2[l2-1] && rst[l1*(s2_len+1)+(l2-1)])
            {
                rst[l1*(s2_len+1)+l2] = true;
            }
            else
            {
                rst[l1*(s2_len+1)+l2] = false;
            }
        }
    }
    ret = rst[s1_len*(s2_len+1)+s2_len];
/*
    for(i=0; i<(s1_len+1)*(s2_len+1); i++)
    {
        printf("i=%d    %s\n", i, rst[i]?"True":"False");
    }
*/
    free(rst);
    rst == NULL;
    return ret;
}


