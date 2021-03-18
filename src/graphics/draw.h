// init
int blockSize = (int) screenHeight/(rayDistance + 1);
int spaceSize = (screenHeight - blockSize) / 2;
// make frame
for (int i=0; i < spaceSize; ++i) frame[rayN][i] = ' ';
for (int i=spaceSize; i < blockSize + spaceSize; ++i) frame[rayN][i] = textures[(int) rayDistance];
for (int i=spaceSize+blockSize; i < screenHeight; ++i) frame[rayN][i] = ' ';

