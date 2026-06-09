题目你可以理解为竞选：
1.概况：1-N个人竞选出镇上有且仅有一位的镇长
2.无效选举情况：候选人如果参加竞选就不能投票，否则违规，无法成为镇长（怕自己投给自己）
3.选民权利：为了避免作弊，必须实名投票，且可以投给多人（你不知道谁不竞选，所以允许投给多人）
4.镇长条件：镇长必须获得N-1张票才可以，


```
/**
*
*整体思路：
*1.申请动态内存，存储每个人被信任的情况，以及每个人是否有信任的人
*2.清空缓冲区，
*3.遍历信任数组，对缓冲区信任的人进行投票，并记录自己编号
*4.遍历缓冲区，如果有一个人被信任了N-1次，且不信任任何人，他就是法官，返回其编号
*5.返回-1
*/

int findJudge( int N , int ** trust , int trustSize , int * trustColSize ){

    //if the length of trust is less than 1, return 1
    if( N < 1 || trustSize < 1 ){

        return 1;

    }

    //alloclating memory to mark everyone's note
    int * buffer = ( int * )malloc( sizeof( int ) * N );

    //clearing the memory
    for( int i = 0 ; i < N ; i++ ){

        *( buffer + i ) = 0;

    }

    //calculating the number of notes in everyone
    for( int i = 0 ; i < trustSize ; i++ ){

        *( buffer + *( *( trust + i ) + 0 ) - 1 ) 
                            = 10000 + *( buffer + *( *( trust + i ) + 0 ) - 1 );
        *( buffer + *( *( trust + i ) + 1 ) - 1 ) += 1;

    }

    //trying to find the judge
    for( int i = 0 ; i < N ; i++ ){

        if( *( buffer + i ) % 10000 == N - 1 && *( buffer + i ) / 10000 == 0 ){

            free( buffer );
            return i + 1;

        }

    }

    //can not find the judge
    free( buffer );
    return -1;

}
```
