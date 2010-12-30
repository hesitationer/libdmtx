#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <assert.h>
#include "../../dmtx.h"
#include "multi_test.h"

/**
 *
 *
 */
DmtxValueGrid *
dmtxValueGridCreate(int width, int height, int type)
{
   DmtxValueGrid *valueGrid;

   valueGrid = (DmtxValueGrid *)calloc(1, sizeof(DmtxValueGrid));
   if(valueGrid == NULL)
      return NULL;

   valueGrid->width = width;
   valueGrid->height = height;
   valueGrid->type = type;
   valueGrid->ref = NULL;

   valueGrid->value = (int *)malloc(width * height * sizeof(int));
   if(valueGrid->value == NULL)
   {
      dmtxValueGridDestroy(&valueGrid);
      return NULL;
   }

   return valueGrid;
}

/**
 *
 *
 */
DmtxPassFail
dmtxValueGridDestroy(DmtxValueGrid **valueGrid)
{
   if(valueGrid == NULL || *valueGrid == NULL)
      return DmtxFail;

   if((*valueGrid)->value != NULL)
      free((*valueGrid)->value);

   free(*valueGrid);
   *valueGrid = NULL;

   return DmtxPass;
}

/**
 *
 *
 */
int
dmtxValueGridGetWidth(DmtxValueGrid *valueGrid)
{
   if(valueGrid == NULL)
      return DmtxUndefined;

   return valueGrid->width;
}

/**
 *
 *
 */
int
dmtxValueGridGetHeight(DmtxValueGrid *valueGrid)
{
   if(valueGrid == NULL)
      return DmtxUndefined;

   return valueGrid->height;
}

/**
 *
 *
 */
int
dmtxValueGridGetValue(DmtxValueGrid *valueGrid, int x, int y)
{
   int idx;

   if(valueGrid == NULL)
      return DmtxUndefined;

   if(x < 0 || x >= valueGrid->width || y < 0 || y >= valueGrid->height)
      return 0;

   idx = y * valueGrid->width + x;

   return valueGrid->value[idx];
}
