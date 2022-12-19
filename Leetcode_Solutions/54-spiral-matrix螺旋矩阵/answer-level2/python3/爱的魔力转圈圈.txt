执行用时:20ms,在所有Python提交中击败了80.35%的用户；内存消耗:11.7MB,在所有Python提交中击败了33.18%的用户

    def spiralOrder(self, matrix):
        if not matrix:return []
        
        zuo=0
        you=len(matrix[0])
        shang=0
        xia=len(matrix)

        k=0
        res=[]
        while True:
            num_shang=matrix[k][zuo:you]

            if shang+1==xia:
                num_xia=[]
            else:
                num_xia=matrix[len(matrix)-1-k][zuo:you][::-1]

            num_you=[]
            for i in range(shang+1,xia-1):
                num_you.append(matrix[i][len(matrix[0])-1-k])

            if zuo+1==you:
                num_zuo=[]
            else:
                num_zuo=[]
                for i in range(shang+1,xia-1):
                    num_zuo.append(matrix[i][k])
                num_zuo=num_zuo[::-1]

            res=res+num_shang+num_you+num_xia+num_zuo

            if shang+1==xia or shang+2==xia or zuo+1==you or zuo+2==you:
                break

            k+=1
            shang+=1
            xia-=1
            zuo+=1
            you-=1

        return res