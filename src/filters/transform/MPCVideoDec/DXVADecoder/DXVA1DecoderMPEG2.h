/*
 * (C) 2006-2015 see Authors.txt
 *
 * This file is part of MPC-BE.
 *
 * MPC-BE is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * MPC-BE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include "DXVA1Decoder.h"
#include <ffmpeg/libavcodec/dxva_mpeg2.h>

class CDXVA1DecoderMPEG2 : public CDXVA1Decoder
{
	DXVA_MPEG2_Context	m_DXVA_Context;

	WORD				m_wRefPictureIndex[2];
	int					m_nNextCodecIndex;

	void				UpdatePictureParams(int nSurfaceIndex);

public:
	CDXVA1DecoderMPEG2(CMPCVideoDecFilter* pFilter, IAMVideoAccelerator*  pAMVideoAccelerator, int nPicEntryNumber);

	virtual void		Flush();
	virtual void		CopyBitstream(BYTE* pDXVABuffer, BYTE* pBuffer, UINT& nSize);
	virtual HRESULT		DeliverFrame(int got_picture, REFERENCE_TIME rtStart, REFERENCE_TIME rtStop);

protected :
	virtual int			FindOldestFrame();
};
