
# emmm....


```



int numJewelsInStones(char * J, char * S){


  int count = 0;
  for(int i = 0; S[i] != '\0'; ++i)

  {

   for(int j = 0; J[j] != '\0'; ++j)

       {

            if(S[i]==J[j])

                ++count;       
        }
   }
return count;                        }
