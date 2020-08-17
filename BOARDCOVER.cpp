#include <iostream>
#include <vector>
using namespace std;
// 순서는 존재하지 않지만 강제로 순서 정하는 것이 point
const int blockType[4][3][2] = {
    {{0, 0}, {0, 1}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}}};
vector<vector<int>> board;
int C = 0, H = 0, W = 0;

//블럭이 들어맞는지 확인하는 함수
bool isSet(vector<vector<int>> &board, int y, int x, int type, int num)
{
    bool ok = true;
    for (int i = 0; i < 3; i++)
    {
        int ny = y + blockType[type][i][0];
        int nx = x + blockType[type][i][1];

        if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
            ok = false;

        else if ((board[ny][nx] += num) > 1)
            ok = false;
    }
    return ok;
}

int cover(vector<vector<int>> &board)
{
    int y = -1;
    int x = -1;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 0)
            {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1)
            break;
    }

    if (y == -1 && x == -1)
        return 1;

    int ans = 0;
    for (int type = 0; type < 4; type++)
    {
        if (isSet(board, y, x, type, 1))
        {
            ans += cover(board);
            //cout << ans << endl;
        }
        isSet(board, y, x, type, -1);
    }

    return ans;
}

int main()
{
    cout << "press." << endl;
    cin >> C;
    for (int i = 0; i < C; i++)
    {
        cin >> H >> W;
        for (int i = 0; i < H; i++)
        {
            vector<int> v(W, 0);
            board.push_back(v);
        }
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                char input;
                cin >> input;
                if (input == '#')
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
        int ans = cover(board);
        cout << "answer : " << ans << endl;
        board.clear();
    }
}