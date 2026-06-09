



class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

        int x1=0;
        int y1=0;
        int x2=0;
        int y2=0;
        int total=(C-A)*(D-B)+(G-E)*(H-F);
        
        if(C>E&&A<G){

            if(A>=E&&C<=G){
                x1=A;
                x2=C;
            }else if (A<=E&&C<=G){
                x1=E;
                x2=C;

            }else if(A<=E&&C>=G){
                x1=E;
                x2=G;
            }else {
                x1=A;
                x2=G;
            }


            if(D>F&&B<H){
                if(B>=F&&D<=H){
                    y1=B;
                    y2=D;
                }else if (B<=F&&D<=H){
                    y1=F;
                    y2=D;

                }else if(B<=F&&D>=H){
                    y1=F;
                    y2=H;
                }else {
                    y1=B;
                    y2=H;
                }
            }
        }



        return total-(x2-x1)*(y2-y1);
    }
}