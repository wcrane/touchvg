// GiSkiaView.cpp
// Copyright (c) 2012, Zhang Yungui
// License: LGPL, https://github.com/rhcad/touchvg

#include "GiSkiaView.h"
#include "GiCmdAndr.h"
#include <mgshapest.h>
#include <list>
#include <mgstoragebs.h>

GiSkiaView::GiSkiaView(GiCanvasBase& canvas) : m_canvas(canvas)
{
    m_shapes = new MgShapesT<std::list<MgShape*> >;
    m_cmdc = new GiCmdController;
}

GiSkiaView::~GiSkiaView()
{
    delete m_cmdc;
    if (m_shapes)
        m_shapes->release();
}

bool GiSkiaView::saveShapes(MgStorageBase* s)
{
    return s && m_shapes && m_shapes->save(s);
}

bool GiSkiaView::loadShapes(MgStorageBase* s)
{
    return s && m_shapes && m_shapes->load(s);
}

int GiSkiaView::getWidth() const
{
    return m_canvas.xf().getWidth();
}

int GiSkiaView::getHeight() const
{
    return m_canvas.xf().getHeight();
}

void GiSkiaView::onSize(int width, int height)
{
    m_canvas.xf().setWndSize(width, height);
}

bool GiSkiaView::onDraw()
{
	m_canvas.rawLine(1, 2, 3, 4);

	mgvector<float> lines(3);
	lines.set(0, 11);
	lines.set(1, 22);
	lines.set(2, 33);
	m_canvas.rawLines(lines);

    return false;
}
