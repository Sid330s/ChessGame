#include <iostream>
using namespace std;


char ch='n';


class Piece {
 
    

   public:
      int pieceatxy;
      char team;
      int forDiagonally(int &sr,int &sc,int &dr,int &dc);
      int forRow(int &sr,int &sc,int &dr,int &dc);
      int forColumn(int &sr,int &sc,int &dr,int &dc);
};

class Spot{
public:
  Piece * P;

  void setPiece( Piece * P )
  {
     this->P= P;
  }                                      //object sclicing

   Piece * getPiece()
   {
        return this->P;
   }

};

Spot chessBoard[8][8];

class King : public Piece {
public:
  
    King(char team='n'){
       pieceatxy=4;
       this->team=team;
    }
    
     int isMoveValid(int &sr,int &sc,int &dr,int &dc)    {
        
          if(((dr==sr+1 || dr==sr-1) && (dc==sc+1 || dc==sc-1)) || ((dr==sr+1 || dr==sr-1) && (dc==sc)) || ((dc==sc+1 || dc==sc-1) && (dr==sr)))
                    return 1;
                else
                    return 0;
     }

};

class Queen : public Piece {
public:

    Queen(char team='n'){
       pieceatxy=5;
       this->team=team;
    }
    
    int isMoveValid(int &sr,int &sc,int &dr,int &dc)    {
        
           if(sr==dr)                                                 //if queen moves in a horizontal row
                {
                    if(forRow(sr,sc,dr,dc))
                        return 1;
                    else
                        return 0;

                }

                else if(sc==dc)                                     //if moves in a vertical column
                {
                    if(forColumn(sr,sc,dr,dc))
                        return 1;
                    else
                        return 0;

                }

                else if(forDiagonally(sr,sc,dr,dc))
                    return 1;

                else
                    return 0;
                    
     }

};

class Bishop : public Piece {

public:
    Bishop(char team='n'){
      pieceatxy=3;
       this->team=team;
    }
    
    int isMoveValid(int &sr,int &sc,int &dr,int &dc)    {
         if(forDiagonally(sr,sc,dr,dc))
                    return 1;
                else
                    return 0;
     }

};

class Knight : public Piece {

public:

    Knight(char team='n'){
       pieceatxy=2;
       this->team=team;
    }
    
    int isMoveValid(int &sr,int &sc,int &dr,int &dc)    {
        
          if((dr==sr+2 && dc==sc+1) || (dr==sr+2 && dc==sc-1) || (dr==sr-2 && dc==sc+1) || (dr==sr-2 && dc==sc-1)|| (dc==sc+2 && dr==sr+1) || (dc==sc+2 && dr==sr-1)|| (dc==sc-2 && dr==sr+1) || (dc==sc-2 && dr==sr-1))
                    return 1;
                else
                    return 0;
     }


};

class Rook : public Piece {
public:

    Rook(char team='n'){
       pieceatxy=1;
       this->team=team;
    }
    
    int isMoveValid(int &sr,int &sc,int &dr,int &dc)    {
        
         if(dr==sr)
                {
                    if(forRow(sr,sc,dr,dc))
                        return 1;
                    else
                        return 0;
                }
                else if(sc==dc)
                {
                    if(forColumn(sr,sc,dr,dc))
                        return 1;
                    else
                        return 0;
                }
                else
                    return 0;
        }
    

};

class Pawn : public Piece {
public:


    Pawn(char team='n'){
       pieceatxy=6;
       this->team=team;
    }
    
    int isMoveValid(int &sr,int &sc,int &dr,int &dc)    {
        
           if(chessBoard[sr][sc].getPiece()->team=='b')
                {
                    if(chessBoard[dr][dc].getPiece()->team=='w')
                        if(dr==sr+1 && (dc==sc+1 || dc==sc-1))
                            return 1;
                        else
                            return 0;
                    else if(sr==1)
                    {
                        if((dr==sr+1 || dr==sr+2) && dc==sc)
                            return 1;
                        else
                            return 0;
                    }
                    else if(dr==sr+1 && dc==sc)
                        return 1;
                    else
                        return 0;
                }

                else
                {
                    if(chessBoard[dr][dc].getPiece()->team=='b')
                        if(dr==sr-1 && (dc==sc+1 || dc==sc-1))
                            return 1;
                        else
                            return 0;
                    else if(sr==6)
                    {
                        if((dr==sr-1 || dr==sr-2) && dc==sc)
                            return 1;
                        else
                            return 0;
                    }
                    else if(dr==sr-1 && dc==sc)
                        return 1;
                    else
                        return 0;
                }
     }

};

class Empty:public Piece{
public:

    Empty(char team='n'){
       pieceatxy=0;
       this->team=team;
    }
    
    int isMoveValid(int &sr,int &sc,int &dr,int &dc)    {
        
          if(((dr==sr+1 || dr==sr-1) && (dc==sc+1 || dc==sc-1)) || ((dr==sr+1 || dr==sr-1) && (dc==sc)) || ((dc==sc+1 || dc==sc-1) && (dr==sr)))
                    return 1;
                else
                    return 0;
     }
};





class Game{

public:
    int i;
    char reply;
public:
    Game(){


      for(int i=0;i<8;i++)
      {
          chessBoard[1][i].setPiece(new Pawn('b'));
          chessBoard[6][i].setPiece(new Pawn('w'));
      }

      chessBoard[0][0].setPiece(new Rook('b'));
      chessBoard[0][7].setPiece(new Rook('b'));
      chessBoard[7][0].setPiece(new Rook('w'));
      chessBoard[7][7].setPiece(new Rook('w'));

      chessBoard[0][1].setPiece(new Knight('b'));
      chessBoard[0][6].setPiece(new Knight('b'));
      chessBoard[7][1].setPiece(new Knight('w'));
      chessBoard[7][6].setPiece(new Knight('w'));

      chessBoard[0][2].setPiece(new Bishop('b'));
      chessBoard[0][5].setPiece(new Bishop('b'));
      chessBoard[7][2].setPiece(new Bishop('w'));
      chessBoard[7][5].setPiece(new Bishop('w'));

      chessBoard[0][3].setPiece(new Queen('b'));
      chessBoard[0][4].setPiece(new King('b'));
      chessBoard[7][3].setPiece(new Queen('w'));
      chessBoard[7][4].setPiece(new King('w'));


      for(int i=2;i<6;i++) for(int j=0;j<8;j++) chessBoard[i][j].setPiece(new Empty('n'));

    }


    int check(int sr,int sc,int dr,int dc,char ch)
    {
        if(chessBoard[sr][sc].getPiece()->pieceatxy!=0 && chessBoard[sr][sc].getPiece()->team==ch)
        {
            if(chessBoard[dr][dc].getPiece()->pieceatxy==0 || chessBoard[dr][dc].getPiece()->team==((ch=='b')?'w':'b'))
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }

    int forDiagonally(int &sr,int &sc,int &dr,int &dc)
    {
                if(sr>dr && sc<dc)
                {
                    for(i=1;i<sr-dr;i++)
                    {
                        if(chessBoard[sr-i][sc+i].getPiece()->pieceatxy!=0)
                        {
                            if(chessBoard[sr-i][sc+i].getPiece()->team==ch)
                            {
                                cout<<"Own Player in path";
                                cout<<"Cant attack";
                                return 0;
                            }
                            else
                            {
                                label3:
                                    cout<<"Do u want to take over the piece in path(y/n):";
                                        cin>>reply;
                                        if(reply=='y' || reply=='Y')
                                        {
                                            dr=dr+(dr-sr-i);
                                            dc=dc-(dr-sr-i);
                                            break;
                                        }
                                        else if(reply=='n' || reply=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nGive answer appropriately";
                                            goto label3;

                                        }

                            }
                        }
                    }
                    return 1;
                }


                else if(sr<dr && sc>dc)
                {
                    for(i=1;i<dr-sr;i++)
                    {
                        if(chessBoard[sr+i][sc-i].getPiece()->pieceatxy!=0)
                        {
                            if(chessBoard[sr+i][sc-i].getPiece()->team==ch)
                            {
                                cout<<"Own Player in path";
                                cout<<"Cant attack";
                                return 0;
                            }
                            else
                            {
                                label4:
                                    cout<<"Do u want to take over the piece in path(y/n):";
                                        cin>>reply;
                                        if(reply=='y' || reply=='Y')
                                        {
                                            dr=dr-(dr-sr-i);
                                            dc=dc+(dr-sr-i);
                                            break;
                                        }
                                        else if(reply=='n' || reply=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nGive answer appropriately";
                                            goto label4;

                                        }

                            }
                        }
                    }
                    return 1;
                }

                else if(sr<dr && sc<dc)
                {
                    for(i=1;i<dr-sr;i++)
                    {
                        if(chessBoard[sr+i][sc+i].getPiece()->pieceatxy!=0)
                        {
                            if(chessBoard[sr+i][sc+i].getPiece()->team==ch)
                            {
                                cout<<"Own Player in path";
                                cout<<"Cant attack";
                                return 0;
                            }
                            else
                            {
                                label5:
                                    cout<<"Do u want to take over the piece in path(y/n):";
                                        cin>>reply;
                                        if(reply=='y' || reply=='Y')
                                        {
                                            dr=dr-(dr-sr-i);
                                            dc=dc-(dr-sr-i);
                                            break;
                                        }
                                        else if(reply=='n' || reply=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nGive answer appropriately";
                                            goto label5;

                                        }

                            }
                        }
                    }
                    return 1;
                }

                else
                {
                    for(i=1;i<sr-dr;i++)
                    {
                        if(chessBoard[sr-i][sc-i].getPiece()->pieceatxy!=0)
                        {
                            if(chessBoard[sr-i][sc-i].getPiece()->team==ch)
                            {
                                cout<<"Own Player in path";
                                cout<<"Cant attack";
                                return 0;
                            }
                            else
                            {
                                 label6:
                                    cout<<"Do u want to take over the piece in path(y/n):";
                                        cin>>reply;
                                        if(reply=='y' || reply=='Y')
                                        {
                                            dr=dr+(sr-dr-i);
                                            dc=dc+(sr-dr-i);
                                            break;
                                        }
                                        else if(reply=='n' || reply=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nGive answer appropriately\n";
                                            goto label6;

                                        }
                            }
                        }
                    }
                    return 1;
                }
    }


    int forRow(int &sr,int &sc,int &dr,int &dc)
    {
                    if(dc<=sc)
                    {
                        for(i=sc-1;i>=dc+1;i--)
                        {
                            if(chessBoard[sr][i].getPiece()->pieceatxy!=0)
                            {
                                if(chessBoard[sr][i].getPiece()->team==ch)               //if path contains the attacking team piece
                                {
                                    cout<<"\nOwn Player in path\n";
                                    cout<<"Can't attack\n";
                                    return 0;
                                }

                                else
                                {
                                    label7:                               //if path contains opponents piece
                                        cout<<"Do u want to take over the piece in path(y/n):";
                                        cin>>reply;                         //asking if want to take over the piece in path
                                        if(reply=='y' || reply=='Y')
                                        {
                                            dc=i;
                                            break;
                                        }
                                        else if(reply=='n' || reply=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nGive answer appropriately\n";
                                            goto label7;
                                        }
                                }
                            }
                        }

                    }
                    else
                    {
                        for(i=sc+1;i<=dc-1;i++)
                        {
                            if(chessBoard[i][sc].getPiece()->pieceatxy!=0)
                            {
                                if(chessBoard[sr][sc].getPiece()->team==ch)
                                {
                                    cout<<"\nOwn Player in path\n";
                                    cout<<"Can't attack\n";
                                    return 0;
                                }
                                else
                                {
                                    label8:
                                        cout<<"Do u want to take over the piece in path(y/n):";
                                        cin>>reply;
                                        if(reply=='y' || reply=='Y')
                                        {
                                            dc=i;
                                            break;
                                        }
                                        else if(reply=='n' || reply=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nGive answer appropriately";
                                            goto label8;
                                        }
                                }
                            }
                        }
                    }
                    return 1;
    }


    int forColumn(int &sr,int &sc,int &dr,int &dc)
    {
                    if(sr<=dr)
                    {
                        for(i=sr+1;i<=dr-1;i++)
                        {
                            if(chessBoard[i][sc].getPiece()->pieceatxy!=0)
                            {
                                if(chessBoard[i][sc].getPiece()->team==ch)
                                {
                                    cout<<"Own Player in path";
                                    cout<<"cant attack";
                                    return 0;
                                }
                                else
                                {
                                    label9:
                                        cout<<"Do u want to take over the piece in path(y/n):";
                                        cin>>reply;
                                        if(reply=='y' || reply=='Y')
                                        {
                                            dr=i;
                                            break;
                                        }
                                        else if(reply=='n' || reply=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nGive answer appropriately";
                                            goto label9;
                                        }
                                }
                            }
                        }
                    }

                    else                                     //wrongly written this else part.modifications required
                    {
                        for(i=sr-1;i>=dr+1;i--)
                        {
                            if(chessBoard[i][sc].getPiece()->pieceatxy!=0)
                            {
                                if(chessBoard[sr][sc].getPiece()->team==ch)
                                {
                                    cout<<"\nOwn Player in path\n";
                                    cout<<"Can't attack\n";
                                    return 0;
                                }
                                else
                                {
                                    label10:
                                        cout<<"Do u want to take over the piece in path(y/n):";
                                        cin>>reply;
                                        if(reply=='y' || reply=='Y')
                                        {
                                            dc=i;
                                            break;
                                        }
                                        else if(reply=='n' || reply=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nGive answer appropriately";
                                            goto label10;
                                        }
                                }
                            }
                        }
                    }
                    return 1;
    }

    int isMoveValid(int &sr,int &sc,int &dr,int &dc)                       //checks whether move is valid
    {
        switch(chessBoard[sr][sc].getPiece()->pieceatxy)
        {
        
            case 4: {  King k;   return k.isMoveValid(sr,sc,dr,dc);
                                                                                 
             //for king
              break;}
            case 5:{
             //queen
             Queen q;   return q.isMoveValid(sr,sc,dr,dc);
              break;}
            case 3:{
               //bishop
              Bishop b;   return b.isMoveValid(sr,sc,dr,dc);
              break;}
            case 6:{
                //pawn
               Pawn p;   return p.isMoveValid(sr,sc,dr,dc);
                break;}
            case 2: {
            //knight  
            Knight k;   return k.isMoveValid(sr,sc,dr,dc);
                 break;}
            case 1:{
            Rook r;   return r.isMoveValid(sr,sc,dr,dc);
              //rook
              break;}
              
    }
    
    return 0;


}







void movePiece(int sr,int sc,int dr,int dc)
{
    chessBoard[dr][dc].getPiece()->pieceatxy=chessBoard[sr][sc].getPiece()->pieceatxy;
    chessBoard[dr][dc].getPiece()->team=chessBoard[sr][sc].getPiece()->team;
    chessBoard[sr][sc].getPiece()->pieceatxy=0;
    chessBoard[sr][sc].getPiece()->team='n';
}


void display()
{
    cout<<endl<<endl;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
            cout<<chessBoard[i][j].getPiece()->pieceatxy<<"  ";
        cout<<endl;

    }
    cout<<endl;

}

};



int main(){

   Game obj;

     int i;

     char reply;

     obj.display();

     int timer =0;

     int sr,sc,dr,dc;



     cout<<"Lets START the game";

     label1:

     if(timer++%2==0)
     {
         cout<<"\nBLACK turn\n";
         ch='b';
     }
     else
     {
         cout<<"\nWHITE turn\n";
         ch='w';
     }

     cout<<"Enter source row and column:";
     cin>>sr>>sc;

     cout<<"\nEnter destination row and column:";
     cin>>dr>>dc;

     cout<<endl;



     if(sr>=8 && sr<=-1 && sc>=8 && sc<=-1 && dr>=8 && dr<=-1 && dc>=8 && dc<=-1 && sr==dr && sc==dc)
     {
         cout<<"\nWrong Input\n";
         timer-=1;
         goto label1;
     }

     int a,b,c,d;
         a=sr-1;
         b=sc-1;
         c=dr-1;
         d=dc-1;

         if(obj.check(a,b,c,d,ch))
         {

             if(obj.isMoveValid(a,b,c,d))
             {
                obj.movePiece(a,b,c,d);

                obj.display();

             }
             else
             {
                 cout<<"\nWrong Input\n";
                 timer-=1;
                 goto label1;
             }
         }
         else
         {
             cout<<"\nWrong Input\n";
             timer-=1;
             goto label1;
         }

         int flag=0;

         for(int i=0;i<8;i++)
         {
             for(int j=0;j<8;j++)
                 if(chessBoard[i][j].getPiece()->pieceatxy==4)
                     flag++;
         }
         if(flag==2)
             goto label1;
         else
         {
             if(ch=='b')
                cout<<"\n BLACK WINS \n";
             else
                 cout<<"\nWHITE WINS\n";
         }

  return 0;
}

